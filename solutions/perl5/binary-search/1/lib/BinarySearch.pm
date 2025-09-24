package BinarySearch;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<binary_search>;

sub binary_search ( $array, $value ) {
    my @values = @{$array};
    die "value not in array" unless @values;
    my $mid = int((scalar @values)/2);
    return $mid if $value == $values[$mid];
    die "value not in array" if $mid == $#values || $mid == 0;
    my @left = @values[0..($mid - 1)];
    my @right = @values[($mid + 1)..$#values];
    return $value > $values[$mid] ? $mid + 1 + binary_search(\@right, $value) : binary_search(\@left, $value);
}

1;
