package NucleotideCount;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<count_nucleotides>;

sub count_nucleotides ($strand) { 
    my %result = (
            A => 0,
            C => 0,
            T => 0,
            G => 0
    );
    
    foreach my $nuc (split //, $strand) {
        die "Invalid nucleotide in strand" if !exists $result{$nuc};
        $result{$nuc}++;
    }
    
    return \%result;
}

1;
