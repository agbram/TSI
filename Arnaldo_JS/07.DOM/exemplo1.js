//Acessar elementos do DOM

// getElementById: acessa elementos pelo atributo id da tag

const subtitulo = document.getElementById("sub1");

console.log(subtitulo.innerHTML);

// getElementByTagName: acessa elesmentos pelo nome da tag
// Retorna uma HTMLCollecion (funciona parecido com um array)
const paragrafos = document.getElementsByTagName("p");

// console.log(paragrafos[1].innerHTML);

for (let i = 0; i < paragrafos.length; i++) {
  console.log(`Paragrafo ${i}: ${paragrafos[i].innerHTML} `);
}

// getElementsByClassName: acessa todos elementos de uma mesma classe. Também retorna um HTMLCollecion

const destaques = document.getElementsByClassName("destaque");

for (let i = 0; i < destaques.length; i++) {
  destaques[i].style.color = "red";
  destaques[i].style.backgroundColor = "yellow";
}

//querySelector: acessa os elementos pelo seletor CSS
//querySelectorAll
const d = document.querySelectorAll(".destaque");

for (let i = 0; i < destaques.length; i++) {
  d[i].style.color = "green";
}

const link = document.querySelector("a")
link.href = 'httP://www.google.com';
link.innerHTML = "Google"
link.target = "_blank"
link.style.fontFamily = 'Arial';

//1 cria um novo no
const novoLink = document.createElement("a");

novoLink.href = 'http://www.ifsp.edu.br'
novoLink.innerHTML = "IFSP"
novoLink.target = "_blank"
link.style.fontFamily = 'Arial';

//2 adiciona o novo no ao no pai
const secao = document.getElementById('primeira');

//Adiciona um novo link no final da secao
//secao.appendChild(novoLink)

//insertBefore(): insere nó antes de outro nó
const p = document.getElementsByTagName('p')[1];

secao.insertBefore(novoLink, p);


const h1 = document.querySelector('h1');
h1.remove();

//removeChild()
const pai = document.querySelector('main');
const filho = document.querySelector('#primeira');

//pai.removeChild()
filho.parentElement.removeChild(filho);



