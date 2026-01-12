package Grains;

use v5.40;
use bigint;

use Exporter qw<import>;
our @EXPORT_OK = qw<grains_on_square total_grains>;

sub grains_on_square ($square) {
    die "square must be between 1 and 64" if $square <= 0 or $square > 64;
    return 2 ** ($square - 1);
}

sub total_grains () {
    return (2 ** 64) - 1;
}

1;
