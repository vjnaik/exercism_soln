package RNA;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<to_rna>;

our %my_conv_map = ('A' => 'U',
                    'T' => 'A',
                    'C' => 'G',
                    'G' => 'C');
sub to_rna ($dna) {
    return join "", map { $my_conv_map{$_} } split //, $dna;
}

1;
