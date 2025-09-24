use v5.40;
use experimental qw<class>;

class DndCharacter;

field $strength :reader;
  field $dexterity :reader;
  field $constitution :reader;
  field $intelligence :reader;
  field $wisdom :reader;
  field $charisma :reader;
  field $hitpoints :reader;

ADJUST {
    $strength = $self->ability();
	$dexterity = $self->ability();
	$constitution = $self->ability();
	$intelligence = $self->ability();
	$wisdom = $self->ability();
	$charisma = $self->ability();
	$hitpoints = 10 + $self->modifier($self->constitution);
}

sub modifier($self, $constitution) {
    return int($constitution/2) - 5;
}

sub ability($self){
    return 3 + int(rand(15)); 
}
1;