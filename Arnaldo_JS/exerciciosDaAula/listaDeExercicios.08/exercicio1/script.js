
const botao = document.querySelector("#button");
const p = document.querySelector("#paragrafo");

let contador = localStorage.getItem("contador");

if(contador == null){
    contador = 0;
} else {
    contador = Number(contador)
}

p.textContent = contador;

botao.addEventListener("click", () => {
  contador++;
  p.textContent = contador; 
  localStorage.setItem("contador", contador);
});