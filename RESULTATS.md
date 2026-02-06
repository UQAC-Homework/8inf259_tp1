# Résultats d'analyse - TP1 Gestion du traffic

## Tableau des résultats

| Configuration \ Type | `PRIORITY_LIGHT` | `FIXED_LIGHT` | `FOUR_WAY_STOP` |
|----------------------|------------------|---------------|-----------------|
| `EVEN`               | 29.5             | 29.5          | 59.5            |
| `ONEWAY`             | 29.5             | 58.0          | 59.5            |
| `UNBALANCED`         | 29.5             | 41.9          | 59.5            |

*Temps d'attente moyen en tours par véhicule (120 véhicules totaux)*

## Analyse
### Meilleur algorithme par configuration

- **EVEN**: `PRIORITY_LIGHT` / `FIXED_LIGHT`

Contrairement à `FOUR_WAY_STOP`, ces algorithmes utilisent une gestion bidirectionnelle. Ceci permet de gérer deux fois plus de véhicules dans cette configuration.

- **ONEWAY** : `PRIORITY_LIGHT`

Contrairement à `FIXED_LIGHT`, cet algorithme ne gaspille pas de temps sur les routes vides. Il se concentre sur les routes les plus occupées. 

- **UNBALANCED** : `PRIORITY_LIGHT`

Cet algorithme priorise la route la plus occupée. Ceci permet de minimiser le temps d'attente. La pénalité de faire attendre une route de `5` véhicules est moins élevée que celle pour une route de `15` véhicules.

### Observations générales
#### `PRIORITY_LIGHT`
##### Forces
Cet algorithme optimise la pénalité d'attente. Elle permet de réduire au maximum le temps total d'attente. Ceci est fait en priorisant la route la plus occupée.

##### Faiblesses
Si la durée minimale est trop élevée sur une direction avec laquelle le traffic est minime, cet algorithme commence à perdre son efficacité.

Par exemple, nous allons analyser un traffic divisé équitablement sur tous les axes. La durée minimale devrait se rapprocher de la densité de chaque route le plus possible. La durée maximale devrait se rapprocher d'un diviseur entier de la densité de chaque route, si la durée minimale est plus élevée. Voici une table avec différentes durées minimales :

| Durée minimale | Durée maximale | Attente moyenne |
|----------------|----------------|-----------------|
| 3              | 5              | 29.5            |
| 3              | 14             | 29.5            |
| 3              | 600            | 29.5            |

Nous pouvons voir que, peu importe la durée maximale, l'attente moyenne reste la même. Cela est toujours le cas si nous augmentons la durée minimale :

| Durée minimale | Durée maximale | Attente moyenne |
|----------------|----------------|-----------------|
| 1              | 5              | 29.5            |
| 5              | 5              | 29.5            |
| 14             | 5              | 29.5            |
| 60             | 5              | 29.5            |

Cependant, la situation change dès que la durée maximale n'est pas un diviseur entier de la densité et que la durée minimale est plus grande que la durée maximale :

| Durée minimale | Durée maximale | Attente moyenne |
|----------------|----------------|-----------------|
| 1              | 7              | 29.5            |
| 5              | 7              | 29.5            |
| 14             | 7              | 29.7            |
| 60             | 7              | 29.7            |
| 60             | 29             | 30.0            |

Cet algorithme alors dépendant sur les durées données en relation avec la distribution du traffic. Le même traffic pour deux couples de durées différentes donnent différents résultats.

De plus, cet algorithme est plus efficace lorsque le traffic est divisé sur tous les axes. Dans une configuration où les véhicules sont séparés sur la route `NORD` et `OUEST` seulement, son efficacité baisse jusqu'à atteindre celle de `FOUR_WAY_STOP`. Ceci est causé par la perte de la possibilité de gérer le traffic de façon bidirectionnelle.

#### `FIXED_LIGHT`
##### Forces
Cet algorithme performe bien lorsque le traffic est divisé pour avantager ses cycles. Si le traffic est concentré sur `NORD-SUD` et que le cycle pour cette direction est plus élevée que l'autre cycle, cet algorithme permet de facilement gérer le traffic.

##### Faiblesses
Si le cycle est trop élevée sur une direction avec laquelle le traffic est minime, cet algorithme commence à perdre son efficacité.

Par exemple, nous allons analyser un traffic divisé équitablement sur l'axe `NORD-SUD`. Pour rivaliser avec `PRIORITY_LIGHT`, le cycle `NORD-SUD` doit être le plus grand possible, alors que le cycle `EST-OUEST` doit être le plus petit possible. Voici une table avec différents cycles :

| Cycle `NORD-SUD` | Cycle `EST-OUEST` | Attente moyenne |
|------------------|-------------------|-----------------|
| 3                | 3                 | 58.0            |
| 10               | 1                 | 32.0            |
| 60               | 0                 | 29.5            |
| 30               | 30                | 44.5            |
| 1                | 60                | 1799.5          |
| 0                | 60                | INF             |

Cet algorithme est très dépendant de la distribution du traffic. Les mêmes cycles pour deux traffics différents donnent des résultats largement différents.

#### `FOUR_WAY_STOP`
##### Forces
Cet algorithme optimise la pénalité d'attente individuelle. Contrairement à `PRIORITY_LIGHT`, une route avec un véhicule ayant attendu longtemps sera priorisée à la route la plus occupée.

##### Faiblesses
Cet algorithme est très limité par la gestion unidirectionnelle. Le nombre de tours minimal est directement lié à la densité du traffic. Voici l'attente moyenne pour chaque configuration si cet algorithme avait une gestion bidirectionnelle :

| `EVEN` | `ONEWAY` | `UNBALANCED` |
|--------|----------|--------------|
| 29.5   | 29.5     | 29.5         |

### Complexité algorithmique
#### Complexité en temps
Les algorithmes ont une complexité de `O(nm)`. Afin de mettre à jour le nombre de tours attendus, il faut parcourir chaque voiture (`m`) de chaque route (`n`). Bien que certains algorithmes passent davantage de temps (tel que `PRIORITY_LIGHT` avec `O(2nm)`), il reste qu'aucun ne dépasse la complexité donnée.

#### Complexité en espace
Les algorithmes ont une complexité de `O(n + m)`. Afin de stocker les données, il faut un objet par route (`n`) et par véhicule (`m`). Cependant, le nombre de véhicules est pour toutes les routes et non pour chaque route.  

### Conclusion
Dans la majorité des situations, le type `PRIORITY_LIGHT` est le plus efficace. Ce type demande de faire une analyse du traffic afin de pouvoir correctement calibrer les durées. Une fois cette calibration faite, ce type surpasse tous les autres types.