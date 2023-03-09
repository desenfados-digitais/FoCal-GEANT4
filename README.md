# IC-2021-2023
Scripts em C++ utilizados na Iniciação Científica em Física Nuclear a respeito do calorímetro FoCal (***Fo**rward **Cal**orimeter*) do ALICE (***A** **L**arge **I**on **C**ollider **E**xperiment*) realizado em colaboração com CERN. A iniciação foi feita pelo DFN (**D**epartamento de **F**ísica **N**uclear) do IFUSP.

O script deve ser utilizado com o software de simulação [GEANT4](https://geant4.web.cern.ch). Ele simula, de forma simplificada, o funcionamento do FoCal com respeito às colisões com, principalmente, elétrons e fótons.

Para usá-lo, instale o GEANT4 em uma distribuição de Linux (recomenda-se o Ubuntu), juntamente com todas as suas dependências, além do ```cmake``` e ```qt```. Após isso, rode no terminal:
```
  ~/path_to_geant4make/geant4make/$ source geant4make.sh
  ~/path_to_sim/sim/build/$ cmake ..
  ~/path_to_sim/sim/build/$ make
  ~/path_to_sim/sim/build/$ ./sim
  ```
