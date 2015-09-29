# fundament (Drupal 7 module)

Utility module for wegewerk GmbH.

1. Provides an opinionated set of re-usable Drupal 7 utility functions.
1. Changes the default behavior of node_export, so that recently updated nodes are always available for export.
1. Submodule, ctools_url_access, provides a ctools access plugin which can activate Panel Variants based on full URL regex matching.

## Utility functions

* fundament_cache
  * A caching wrapper to place around any expensive function.
* fundament_get_nodes
  * Get a set of node entities without too much fuss.
* fundament_get_terms
  * Get a set of term entities without too much fuss.
* fundament_node_eapi_field_collections_by_field
  * A clean interface for accessing field_collection values.
