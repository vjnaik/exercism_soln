# Declare package 'Bob'
package Bob;

use v5.40;

use Exporter qw<import>;
our @EXPORT_OK = qw<hey>;

my @responses = (
    "Sure.", "Whoa, chill out!", "Calm down, I know what I'm doing!",
    "Fine. Be that way!", "Whatever."
);

sub hey ($msg) {
    return $responses[3] if $msg !~ m/[[:graph:]]/;
    return $responses[1] if $msg =~ m/[A-Z]{2,}.*[^?]$/ && $msg !~ m/[a-z]/;
    return $responses[2] if $msg =~ m/^.[^a-z:)].*\?$/;
    return $responses[0] if $msg =~ m/.*\?\s*$/;
    return $responses[4];
}

1;
