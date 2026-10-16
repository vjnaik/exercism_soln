package ReverseString;

use v5.42;

use Exporter qw<import>;
our @EXPORT_OK = qw<str_reverse>;

sub str_reverse ($text) {
    return join "", reverse($text =~ /\X/g);  # \X multiple code points 4 unicode
}

1;
