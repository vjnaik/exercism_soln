package Isogram;

use v5.42;

use Exporter qw<import>;
use List::Util qw/all/;

our @EXPORT_OK = qw<is_isogram>;

sub is_isogram ($phrase) {
    my %seen;
    $seen{lc $_}++ foreach grep /[A-z]/, split //, $phrase;
    return all { $seen{$_} == 1 } keys %seen;
}

1;