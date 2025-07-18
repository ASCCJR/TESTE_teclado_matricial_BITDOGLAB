# 🎮 Teclado Matricial 4x4 na BitDogLab 

![Linguagem](https://img.shields.io/badge/Linguagem-C-blue.svg)  ![Plataforma](https://img.shields.io/badge/Plataforma-BitDogLab_Pico-purple.svg)  ![Interface](https://img.shields.io/badge/Interface-USB%20Serial-green.svg)  ![Conector](https://img.shields.io/badge/Conector-Peripheral_14pin-orange.svg)  

Este projeto implementa um driver para teclado matricial 4x4 na **BitDogLab**, utilizando o **conector periférico de 14 pinos** com o adaptador dedicado que vem no kit de periféricos.


---

## ✨ **Funcionalidades Principais**  

✅ **Conexão simplificada** usando adaptador para teclado matricial  
✅ **Leitura eficiente** com varredura por colunas otimizada  
✅ **Teclado totalmente mapeável**
✅ **Debounce inteligente** para evitar leituras fantasmas  
✅ **Saída serial limpa** via USB (115200 baud)  
✅ **Espera por conexão USB** antes de iniciar  

---

## 🛠️ **Hardware Necessário**  

### **Componentes**  
- Placa **BitDogLab**  
- Teclado matricial **4x4**  
- **Adaptador** para o conector periférico de 14 pinos
- Cabo USB para alimentação e comunicação  

---

## 🔌 **Como Conectar?**  

O adaptador se encaixa diretamente no **conector periférico de 14 pinos** da BitDogLab, eliminando a necessidade de ficar ligando fio por fio!  

✅ **Sem jumpers extras**  
✅ **Sem confusão de pinagem**  
✅ **Plug and play**  

---

## ⚙️ **Personalização**  

### **1. Mapeamento das Teclas**  
Por padrão, o teclado está configurado assim:  

```c
const char keymap[4][4] = {
    {'D', 'C', 'B', 'A'},
    {'#', '9', '6', '3'},
    {'0', '8', '5', '2'},
    {'*', '7', '4', '1'}
};
```
---

## 📟 **Saída no Terminal Serial**  

Ao abrir o monitor serial (**115200 baud**), você verá:  

```bash
=== TECLADO MATRICIAL 4x4 ===
Pressione uma tecla...
Tecla pressionada: 5
Tecla pressionada: A
Tecla pressionada: #
```

---

## 🚀 **Como Usar?**  

1. **Conecte o adaptador** no conector periférico da BitDogLab  
2. **Encaixe o teclado** no adaptador  
3. **Ligue a placa** via USB  
4. **Abra um terminal serial** (115200 baud)  
5. **Aperte as teclas** e veja a saída!  

---

## 📌 **Dicas Importantes**  

🔹 **Pull-ups internos** 
🔹 **Pronto para integração** com outros projetos  

---

✍️ **Autor**: **Antonio Sergio Castro de Carvalho Junior**  
