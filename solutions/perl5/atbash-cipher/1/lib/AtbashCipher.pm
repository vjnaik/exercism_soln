package AtbashCipher;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<encode_atbash decode_atbash>;

my @a = 'a'..'z';
my %cipher_map = map { $a[$_] => $a[25 - $_] } 0..25;
my %dec_map = reverse %cipher_map;

sub encode_atbash ($phrase) {
    my @temp;
    foreach my $char(split //, lc $phrase){
        next if $char =~ m/[, .]/;
        push(@temp, exists $cipher_map{$char} ? $cipher_map{$char} : $char);
    }
    my ($i, $string) = 0, ""; 
    foreach my $c (@temp) {
        $string .= ' ' if $i == 5;
        $string .= $c;
        $i = $i == 5 ? 1 : $i + 1;
    }
    return $string;
}

sub decode_atbash ($phrase) {
    my @temp = split //, join "", split " ", $phrase;
    my @to_join;
    foreach my $char(@temp){
        push @to_join, exists $dec_map{$char} ? $dec_map{$char} : $char;
    }
    return join "", @to_join;
}

1;
