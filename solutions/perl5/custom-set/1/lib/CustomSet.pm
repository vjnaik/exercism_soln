use v5.40;
use experimental qw<class>;

class CustomSet;

field $elements :reader :param;

method is_empty () {
    return !$elements->@*;
}

method _contains ($element){
    foreach ($elements->@*){
        return 1 if $_ == $element;
    }
    return 0;
}

method contains ($element) {
    return $self->is_empty() ? 0 : $self->_contains($element);
}

method is_subset_of ($other) {
    return 1 if $self->is_empty();
    return 0 if $other->is_empty();
    foreach ($elements->@*){
        return 0 if !$other->contains($_);
    }
    return 1;
}

method is_disjoint_of ($other) {
    return 1 if $self->is_empty() || $other->is_empty();
    foreach ($elements->@*){
        return 0 if $other->contains($_);
    }
    return 1;
}

method is_equal_to ($other) {
    return $self->is_subset_of($other) && $other->is_subset_of($self);
}

method add ($element) {
    push $elements->@*, $element if !$self->contains($element);
    return $self;
}

method intersection ($other) {
    my $inter = CustomSet->new(elements => []);
    return $inter if $self->is_disjoint_of($other);
    foreach ($elements->@*){
        $inter->add($_) if $other->contains($_);
    }
    return $inter;
}

method difference ($other) {
    my $diff = CustomSet->new(elements => []);
    return $diff if $self->is_empty() || $self->is_equal_to($other);
    foreach ($elements->@*){
        $diff->add($_) if !$other->contains($_);
    }
    return $diff;
}

method union ($other) {
    my $uni = CustomSet->new(elements => [$elements->@*]);
    return $uni if $other->is_empty();
    foreach ($other->elements->@*){
        $uni->add($_) if !$self->contains($_);
    }
    return $uni;
}

1;
