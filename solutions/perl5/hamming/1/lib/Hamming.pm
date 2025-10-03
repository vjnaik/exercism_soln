package Hamming;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<hamming_distance>;

sub hamming_distance ( $strand1, $strand2 ) {
    die "strands must be of equal length" 
                    unless length($strand1) == length($strand2);
    
    return 0 if $strand1 eq $strand2;
    
    my $count = 0;
    my @arr1 = split //, $strand1;
    my @arr2 = split //, $strand2;
    
    foreach my $index (0 .. length($strand1)){
        $count += 1 if $arr1[$index] ne $arr2[$index];
    }
    
    return $count;
}

1;
