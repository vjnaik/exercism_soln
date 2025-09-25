package EliudsEggs;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<egg_count>;

sub egg_count ($number) {
    my $sum = 0;
    $sum += $_ foreach split //, sprintf "%b", $number;
    return $sum;
}

1;