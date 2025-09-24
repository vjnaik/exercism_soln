package Allergies;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<allergic_to list_allergies>;

my %allergies = ( "eggs" => 1,
                  'peanuts' => 2,
                  'shellfish' => 4,
                  'strawberries' => 8,
                  'tomatoes' => 16,
                  'chocolate' => 32,
                  'pollen' => 64,
                  'cats' => 128 );

sub allergic_to ( $item, $score ) {
    return $allergies{$item} & $score;
}

sub list_allergies ($score) {
    my @list=();
    foreach my $key(keys %allergies){
        if($score & $allergies{$key}){
           push @list, $key;
        }
    }
    return \@list;
}

1;
