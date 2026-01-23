package ETL;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<transform>;

sub transform ($data) {
    my %result;
    # dereference the hash $data->%*
    foreach my $key ( keys $data->%* ) {
        # dereference the array value ($data->{$key})->@*
        $result{lc $_} = $key foreach $data->{$key}->@*;
    }
    return \%result;
}

1;
