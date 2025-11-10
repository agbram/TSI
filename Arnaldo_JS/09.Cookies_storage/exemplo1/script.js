function getCookie(nomeCookie) {
  let nome = nomeCookie + "=";

  let ca = document.cookie.split(";");

  for (let i = 0; i < ca.length; i++) {
    let c = ca[i];

    //retira espaços em branco no inicio da string
    while (c.charAt(0) == " ") {
      c = c.substring(1);
    }

    //encontrou o cookie
    if (c.indexOf(nome) == 0) {
      //corta a string para pegar o valor do cookie
      return c.substring(nome.length, c.length);
    }
  }
  return "";
}

// Criar cookie
document.cookie = "tema=dark; path=/;";

// Ver todos os cookies
console.log(document.cookie);

// Deletar o cookie "tema"
document.cookie = "tema=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";

// Verificar novamente
console.log(document.cookie);

console.log(getCookie("tema"))
console.log(getCookie("usename"))
