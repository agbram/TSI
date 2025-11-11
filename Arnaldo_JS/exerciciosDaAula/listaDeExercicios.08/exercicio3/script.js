const textarea = document.createElement("textarea");
const botao = document.createElement("button");
botao.textContent = "Limpar";

document.body.appendChild(textarea);
document.body.appendChild(botao);

const textoSalvo = sessionStorage.getItem("texto");

if (textoSalvo) {
  textarea.value = textoSalvo;
}

textarea.addEventListener("input", () => {
  sessionStorage.setItem("texto", textarea.value);
});

botao.addEventListener("click", () => {
  textarea.value = "";
  sessionStorage.removeItem("texto");
});