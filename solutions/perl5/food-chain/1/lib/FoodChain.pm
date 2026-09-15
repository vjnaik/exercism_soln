package FoodChain;

use v5.42;

use Exporter qw<import>;
our @EXPORT_OK = qw<recite>;

my @verse = (
  [ "fly" ], [ "spider" ],
  [ "bird", "How absurd to swallow" ],
  [ "cat", "Imagine that, to swallow" ],
  [ "dog", "What a hog, to swallow" ],
  [ "goat", "Just opened her throat and swallowed" ],
  [ "cow", "I don't know how she swallowed" ],
);

my $spider_verse = "wriggled and jiggled and tickled inside her";

sub recite ( $start, $end ) {
    my $txt; 
    $txt .= ($_ < scalar @verse ? get_verse($_) : qq/I know an old lady who swallowed a horse.\n/
            . qq/She's dead, of course!/) . qq/\n/
            for --$start..--$end;
    chomp $txt;
    return $txt;
}

sub get_verse($i) { 
    my ($animal, $swallow) = $verse[$i]->@*;
    my $txt = qq/I know an old lady who swallowed a $animal.\n/;
    if ($i > 0) {
        $txt .= $i == 1 ? qq{It $spider_verse.\n} : qq/$swallow a $animal!\n/;
        $txt .= qq/She swallowed the $verse[$_]->[0] to catch the $verse[$_-1]->[0]/
                . ($_ == 2 ? qq/ that $spider_verse/ : "") . qq/.\n/ for reverse 1..$i;
    }
    return $txt . qq/I don't know why she swallowed the fly. Perhaps she'll die.\n/;
}

1;