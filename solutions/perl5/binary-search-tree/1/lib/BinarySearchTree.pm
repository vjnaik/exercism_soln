use v5.40;
use experimental qw<class>;

class BinarySearchTree;

field $root :param;

method add ($values) {
    if(!$root){
      $root=BinarySearchTree::Node->new(data => $values);
    }else{
      $root = $self->_add($values, $root);
    }
}
method _add($values, $node){
   return BinarySearchTree::Node->new(data => $values) if !defined $node;

   if($values gt $node->data){
       $node->set_r($self->_add($values, $node->right));
   } else{
       $node->set_l($self->_add($values, $node->left));
   }
   return $node;
}

method sort () {
    my @result;
    $self->_in_order($root,\@result);
    return \@result;
}

method _in_order($node,$result){
    return unless defined $node;

    $self->_in_order($node->left, $result);
    push @$result, $node->data;
    $self->_in_order($node->right, $result);
}

class BinarySearchTree::Node {
    field $data :reader :param;
    field $left :reader;
    field $right :reader;
    
    method set_l($node) {
        $left = $node;
    }
    method set_r($node) {
        $right = $node;
    }
}

1;