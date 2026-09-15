package Gigasecond;

use v5.42;
use Time::Piece;

use Exporter qw<import>;
our @EXPORT_OK = qw<add_gigasecond>;

sub add_gigasecond($time) {
    my $cur_time = Time::Piece->strptime($time, '%Y-%m-%dT%H:%M:%S');
    $cur_time += 10 ** 9; # Giga second
    $cur_time->strftime('%Y-%m-%dT%H:%M:%S')
}

1;