package Accumulate;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<accumulate>;

sub accumulate ( $list, $func ) {
    my @res = ();
    push(@res, $func->($_)) foreach @{$list};
    return $list = \@res;
}

1;
