package AllYourBase;

use v5.40;

use Exporter qw<import>;
use List::Util qw<reduce>;
our @EXPORT_OK = qw<rebase>;

my @errors = (
    'input base must be >= 2',
    'output base must be >= 2',
    'all digits must satisfy 0 <= d < input base',
);

sub rebase ($digits, $input_base, $output_base) {
    die $errors[0] if $input_base < 2;
    die $errors[1] if $output_base < 2;

    foreach my $d (@{$digits}) {
        die $errors[2] if $d < 0 || $d >= $input_base;
    }

    my $sum_in_10 = reduce {$input_base * $a + $b} 0, @{$digits};
    my @output_value;
    return [0] if $sum_in_10 == 0;
    while($sum_in_10 > 0){
        unshift @output_value, $sum_in_10 % $output_base;
        $sum_in_10 = int($sum_in_10 / $output_base);
    }
    return \@output_value;
}

1;
