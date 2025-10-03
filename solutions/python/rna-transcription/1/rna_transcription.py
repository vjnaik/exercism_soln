def to_rna(dna_strand):
    my_conv_map = {'T':'A', 'A':'U',
              'G':'C', 'C':'G'}
    return "".join([my_conv_map[ntide] for ntide in list(dna_strand)])