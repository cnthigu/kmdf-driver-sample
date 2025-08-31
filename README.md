# KMDF Driver Hello World

Este é um **driver simples para Windows** desenvolvido com KMDF (Kernel-Mode Driver Framework) como projeto de estudo.
O objetivo é aprender a compilar, rodar e entender a comunicação entre **Kernel Mode** e **User Mode**.

---

## Estrutura do projeto

- `KMDFDriver3.sys` → Driver compilado (Kernel Mode)
- `KMDFDriver3.inf` → Arquivo INF para instalação (opcional)
- `DriverEntry.cpp` → Código fonte principal
- `README.md` → Este arquivo

---

## Requisitos

- Windows 10 ou superior
- Visual Studio 2022 com suporte C++
- Windows Driver Kit (WDK) instalado
- Windows 11 SDK (opcional, dependendo da versão do WDK)

---

## Como compilar

1. Abra o Visual Studio 2022 como **Administrador**
2. Abra o projeto `KMDF Driver3`
3. Selecione a **configuração**: `x64` → `Debug`
4. Compile o projeto (`Build → Build Solution`)
5. Após compilar, o driver `.sys` será gerado em:

```
KMDF Driver3\x64\Debug\KMDFDriver3.sys
```

---

## Como rodar o driver

1. Ative o **Test Mode** no Windows (se necessário):

```cmd
bcdedit /set testsigning on
```

2. Abra o Prompt de Comando como Administrador.

3. Crie o serviço do driver:

```cmd
sc create KMDFDriver3 type= kernel binPath= "C:\Caminho\Para\SeuDriver\KMDFDriver3.sys"
```

4. Inicie o driver:

```cmd
sc start KMDFDriver3
```

5. Para parar e remover:

```cmd
sc stop KMDFDriver3
sc delete KMDFDriver3
```

---

## Debug

Para visualizar mensagens do driver:

1. Baixe e abra o DebugView da Sysinternals como Administrador.
2. Habilite `Capture → Capture Kernel`.
3. Use Filtros para ver apenas mensagens do driver, por exemplo: `[KMDFDriver3]`.

No código, o driver envia mensagens de debug usando `DbgPrint`:

```c
DbgPrint("[KMDFDriver3] Driver carregado com sucesso!\n");
```

---

## Próximos passos

- Explorar comunicação Kernel → User Mode
- Ler/escrever memória de processos de forma segura
- Entender protocolos e chamadas de kernel

---

### Observação sobre o WDK

Caso encontre problemas de compilação relacionados ao WDK, uma solução comum é instalar o pacote NuGet `Microsoft.Windows.WDK.x64` (por exemplo, versão 10.0.26100.4204). Isso pode resolver dependências e permitir a compilação do projeto.

