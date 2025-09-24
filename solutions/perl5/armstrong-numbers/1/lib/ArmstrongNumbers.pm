package ArmstrongNumbers;

use v5.40;
use List::Util qw<reduce>;
use bigint;

use Exporter qw<import>;
our @EXPORT_OK = qw<is_armstrong_number>;

sub is_armstrong_number ($number) {
    my $exponent = length($number);
    return $number == reduce {$a += $b ** $exponent} 0, map {0 + $_} split //, $number;
}

1;
