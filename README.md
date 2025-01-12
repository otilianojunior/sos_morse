# **sos_morse**
Código para transmitir o sinal SOS em sistemas embarcados utilizando a placa Pico W.

---

## **Passos para executar o projeto no Visual Studio Code utilizando a biblioteca Wokwi**

### **1. Configurar o ambiente de desenvolvimento**
Certifique-se de que o ambiente de desenvolvimento para a Raspberry Pi Pico W esteja configurado no Visual Studio Code. Para isso:
- Instale o **CMake** (requerido para o build do projeto).
- Instale o **SDK da Raspberry Pi Pico** (pico-sdk).
- Configure a extensão oficial da Pico no VS Code.
- Instale a **biblioteca Wokwi** no seu projeto para simulação.

### **2. Clonar ou copiar o projeto**
Certifique-se de que os seguintes arquivos estejam organizados no mesmo diretório:

```
/pasta-do-projeto
    ├── sos_morse.c          # Código fonte
    ├── CMakeLists.txt       # Arquivo de configuração do build
    ├── wokwi.toml           # Configuração da simulação no Wokwi
```

### **3. Configurar o arquivo `CMakeLists.txt`**
Certifique-se de que o arquivo `CMakeLists.txt` contenha o seguinte conteúdo:

```cmake
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
```

### **4. Configurar o arquivo `wokwi.toml`**
Adicione um arquivo `wokwi.toml` na raiz do projeto com o seguinte conteúdo:

```toml
[wokwi]
version = 1
firmware = "build/sos_morse.uf2"
elf = "build/sos_morse.elf"
```

Esse arquivo garante que a simulação do Wokwi utilize o firmware compilado do projeto.

### **5. Criar a pasta de build**
1. Abra o terminal integrado do VS Code.
2. Navegue até a pasta do projeto e crie uma pasta chamada `build`:
   ```bash
   mkdir build && cd build
   ```
3. Configure o build com o CMake:
   ```bash
   cmake ..
   ```

### **6. Compilar o projeto**
Dentro da pasta `build`, compile o projeto com o comando:
```bash
ninja
```
Isso gerará o arquivo `sos_morse.uf2` na pasta `build`.

### **7. Executar o projeto no Wokwi**
1. Certifique-se de que o simulador Wokwi está instalado no seu ambiente.
2. Na raiz do projeto, execute o comando:
   ```bash
   wokwi-server
   ```
3. O Wokwi abrirá a simulação no navegador. Certifique-se de que o LED esteja conectado corretamente à GPIO 13 no arquivo de configuração do Wokwi.

---

## **Observações**
- O LED deve estar configurado na GPIO 13, conforme o código.
- A simulação no Wokwi permite testar o funcionamento do código antes de transferi-lo para a placa física.
- Certifique-se de que o arquivo `CMakeLists.txt` e o `wokwi.toml` estão corretamente configurados para evitar erros durante o build e a simulação.