package Anagram;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<match_anagrams>;

sub _format {
    return join "", sort split //,lc shift;
}

sub match_anagrams ( $subject, $candidates ) {
    my @out;
    foreach my $word(@{$candidates}){
        push (@out, $word) if _format($subject) eq _format($word) && lc($subject) ne lc($word);
    }
    return \@out;
}

1;
