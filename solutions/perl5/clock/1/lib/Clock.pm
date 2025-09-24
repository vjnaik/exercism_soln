use v5.40;
use experimental qw(class);

class Clock;

field $hour   :reader :param;
field $minute :reader :param;

# internal method to calculate minutes since midnight
method _total_minutes () {
    return $hour * 60 + $minute;
}

# Adjust time within 0 to 1439 minutes
method _adjust ($at) {
    $at %= 1440;
    return $at + ($at < 0 ? 1440 : 0);
}

# Return time as HH:MM
method time () {
    my $adj = $self->_adjust($self->_total_minutes);
    return sprintf "%02d:%02d", int($adj / 60), $adj % 60;
}

# Return a new Clock with time added
method add_minutes ($amount) {
    my $new_min = $self->_adjust($self->_total_minutes + $amount);
    return Clock->new(
        hour   => int($new_min / 60),
        minute => $new_min % 60,
    );
}

# Return a new Clock with time subtracted
method subtract_minutes ($amount) {
    my $new_min = $self->_adjust($self->_total_minutes - $amount);
    return Clock->new(
        hour   => int($new_min / 60),
        minute => $new_min % 60,
    );
}

1;