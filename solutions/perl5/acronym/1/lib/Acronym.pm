package Acronym;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<abbreviate>;

sub abbreviate ($phrase) {
    my @list = split /[^[:alnum:]'']/, $phrase;
    my $abbr;
    $abbr .= uc substr $_, 0, 1 foreach @list;
    return $abbr;
}

1;
