package CryptoSquare;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<cipher>;

sub cipher ($text) {
    my $string = "";
    $string .= $_ foreach split /[ [:punct:]]/, lc($text);
    
    my $len = length $string;
    return $string if $len < 2;
    
    my $column = int(0.5 + sqrt $len);
    my $row = 0;
    $row++ until $row * $column >= $len;
    ($row, $column) = ($column, $row) if $row > $column;
    
    my $area = $row * $column;
    $string .= " " x ($area - $len) if $area > $len;
    
    my $result = "";
    for(my $i = 0; $i < $column; $i++){
        for(my $j = $i; $j < $column * $row; $j += $column){
            $result .= substr $string, $j, 1;
        }
        $result .= " " if $i < $column - 1;
    }
    return $result;
}

1;
