package InventoryManagement;

use v5.40;

sub create_inventory ($items) {
    my %inventory;
    $inventory{$_}++ foreach @{$items};
    return \%inventory;
}

sub add_items ( $inventory, $items ) {
    $inventory->{$_}++ foreach @{$items};
    return $inventory;
}

sub remove_items ( $inventory, $items ) {
    foreach my $var (@{$items}){
        $inventory->{$var}-- if $inventory->{$var} != 0;
    }
    return $inventory;
}

sub delete_item ( $inventory, $item ) {
    delete $inventory->{$item};
    return $inventory;
}

1;
