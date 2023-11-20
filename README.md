# Projeto de Controle de Motores com Sensores Ultrassônicos em C++ e Arduino

## Descrição:

Este projeto utiliza um Arduino e sensores ultrassônicos para detectar a distância de objetos em três direções diferentes. Com base nessas leituras, controla motores DC para realizar movimentos específicos quando detecta a proximidade de obstáculos.

### Componentes Utilizados:

- Arduino (ou compatível)
- 3 Sensores Ultrassônicos HC-SR04
- 2 Motores DC com rodas
- Ponte H (L298N ou similar)
- Fios de conexão
- Fonte de alimentação para motores DC

### Bibliotecas:

- [NewPing](https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home): Esta biblioteca facilita a utilização de sensores ultrassônicos no Arduino.

### Pinagem:

- **Sensores Ultrassônicos:**
  - Sensor 1: Trigger - Pino 3, Echo - Pino 2
  - Sensor 2: Trigger - Pino 12, Echo - Pino 11
  - Sensor 3: Trigger - Pino 7, Echo - Pino 6

- **Motores DC:**
  - Motor 1 Esquerdo: ENA - Pino 5, ENB - Pino 10
  - Motor 2 Direito: ENA2 - Pino 4, ENB2 - Pino 9

### Configurações:

- **MAX_DISTANCE:** Define a distância máxima para detecção em centímetros (neste caso, 200 cm).

### Funcionamento:

1. **Setup:**
   - Inicializa a comunicação serial a uma taxa de 9600 bps.
   - Configura os pinos dos motores e dos sensores como saídas ou entradas, conforme necessário.

2. **Loop:**
   - A cada 2 segundos, realiza leituras de distância dos três sensores ultrassônicos.
   - Exibe as leituras no monitor serial.

3. **Controle dos Motores:**
   - Se a distância lida pelo Sensor 1 for inferior a 50 cm, os motores 1 (esquerdo) são acionados.
   - Se a distância lida pelo Sensor 2 for inferior a 50 cm, os motores 2 (direito) são acionados.
   - Se a distância lida pelo Sensor 3 for inferior a 50 cm, ambos os motores são acionados.

### Observações:

- Os motores são desligados quando não há detecção de obstáculos.
- O projeto pode ser adaptado para diferentes comportamentos e movimentos com base nas leituras dos sensores.

