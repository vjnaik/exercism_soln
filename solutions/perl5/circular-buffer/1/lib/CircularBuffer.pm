use v5.40;
use experimental qw<class>;

class CircularBuffer;

field $capacity :reader :param;
field @array = (); 
field $length;
field $head = 0;
field $tail = 0;

method write ($item) {
	die "buffer full" if $capacity <= $length;
	$array[$tail] = $item;
	$tail = ($tail+1) % $capacity;
	$length++;
}

method read () {
	die "buffer empty" if $length <= 0;
	my $item = $array[$head];
	$head = ($head+1) % $capacity;
	$length--;
	return $item;
}

method clear () {
	$length = 0;
	$tail = $head;
}

method overwrite ($item) {
	$self->read() if $capacity <= $length;
	$self->write($item);
}

1;