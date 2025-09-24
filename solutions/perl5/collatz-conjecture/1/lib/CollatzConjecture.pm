package CollatzConjecture;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<steps>;

sub steps ($number) {
    my $count = 0;
    
    die "Only positive integers are allowed" if $number <= 0;
    
    return $count if $number == 1;
    
    while ($number != 1){
        if($number % 2){
            $number = 3 * $number + 1;
        } else {
            $number /= 2;
        }
        $count++;
    }
    
    return $count;
}

1;
