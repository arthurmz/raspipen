
O plano de escrita é sempre o xy.
Isso simplifica, pois dado um ponto no d3, a distância para o 'papel' é sempre z, e o ponto sobre o papel é sempre xy.
Cada deslocamento no 3d deve ser compensado pelo angulosidade sofrida em cada eixo

Conceitualmente, existem dois espaços, 
O espaço do papel, onde os pontos sobre xy devem ser identificados
E o espaço de deslocamento, onde a aceleração é medida, o vetor de deslocamento é determinado, é aplicado o offset da angulosidade,
e o vetor resultante é usado para determinar o próximo ponto no espaço do papel.
------------------------------------------------------------------------------------------

ciclo de vida da aplicação:

obter a aceleração em cada eixo.
calcular o vetor deslocamento da aceleração.  (empiricamente, deve determinar a melhor velocidade inicial)
aplicar o offset da angulosidade (pode pular o passo caso não tenha giroscópio)
somar o ponto atual no espaço do papel com o vetor de deslocamento, obtendo o ponto de destino.
armazenar o ponto no vetor de pontos do papel.
--------------------------------------------------------------------------------------------

Para gerar a imagem:
o vetor de pontos deve guardar sequencias de pontos xy, as distâncias entre os dois devem ser preenchidas com retas na imagem.
além disso, cada ponto deve guardar um FLAG, se é ligado ou não ao ponto anterior, isso define se uma reta deverá ligar
os dois na imágem.

o gerador de imagens deve ler o vetor, e marcar de preto os pixels referentes aos pontos xy, além de os pontos que formam as retas
que ligam cada ponto.


Se tudo que escrevi fizer sentido, a imagem será gerada correspondente à escrita da caneta.