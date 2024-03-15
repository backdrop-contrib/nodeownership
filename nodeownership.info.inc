<?php

/**
 * Class for claim entities.
 */
class ClaimEntityClass extends Entity {

  public $id;

  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, 'claim');
  }

  /**
   * Implements EntityInterface::id().
   */
  public function id() {
      return $this->id;
  }

  /**
  * Implements EntityInterface::label().
  */
  public function label() {
    return 'label';
  }

  /**
  * Implements EntityInterface::uri().
  */
  public function uri() {
    return array(
      'path' => 'nodeownership/' . $this->id,
    );
  }

  /**
  * Implements EntityInterface::entityType().
  */
  public function entityType() {
    return 'nodeownership';
  }

  /**
   * Specifies the default label, which is picked up by label() by default.
   */
  public function defaultLabel() {
    $user  = user_load($this->uid);
    $node  = node_load($this->nid);
    $label = 'Claim #' . $this->id . ': ' . $user->name . '(uid:' . $user->uid . ') claims ' . $node->title . '(nid:' . $node->nid . ')';

    return $label;
  }
}