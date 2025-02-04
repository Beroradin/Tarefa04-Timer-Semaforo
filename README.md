# ✨ Tarefa04-Timers-Semáforo
<p align="center"> Repositório dedicado a Tarefa 04 do processo de capacitação do EmbarcaTech que envolve temporizadores na placa Raspberry Pi Pico W por meio da Placa BitDogLab.</p>

## :clipboard: Apresentação da tarefa

Para consolidar a compreensão dos conceitos relacionados ao uso de temporizadores no microcontrolador RP2040 e explorar as funcionalidades da placa de desenvolvimento BitDogLab, esta atividade propõe a implementação de um projeto prático envolvendo o controle de LEDs que simulam um semáforo por meio de timers.

## :dart: Objetivos

- Compreender o funcionamento e a aplicação de temporizadores em microcontroladores;

- Manipular e controlar LEDs comuns;

- Cada LED deve funcionar por 3 segundos e em seguida se apagar, mandando nível alto para o próximo LED e assim por diante.

- Uma mensagem deve aparecer a cada 1 segundo no loop principal do microcontrolador.

## :books: Descrição do Projeto

Utiizou-se a placa BitDogLab (que possui o microcontrolador RP2040) para o controle de LEDs, esses por sua vez são acionados por meio de um temporizador, que liga cada LED individualmente a cada 3 segundos, em ciclo.
O funcionamento do temporizador ocorre por meio da API de Hardware *add_repeating_timer_ms* que opera de forma externa ao processamento central, não afetando o funcionamento do loop principal, em qual deve aparecer uma mensagem a cada 1 segundo.

## :walking: Integrantes do Projeto

- Matheus Pereira Alves

## :bookmark_tabs: Funcionamento do Projeto

- Os LEDs são acionados por meio da API de Hardware e uma função (callback) auxiliar;
- O LED vermelho deve iniciar em nível alto, enquanto os amarelo e verde em nível baixo;
- O temporizador muda o estado dos LEDs a cada 3 segundos;
- O loop principal printa e incrementa um inteiro a cada 1 segundo.

## :camera: GIF mostrando o funcionamento do programa na placa BitDogLab
<p align="center">
  <img src=".github/semaforo.gif" alt="GIF" width="600px" />
</p>
