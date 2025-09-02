let mensagem = "Olá, hojé é ";

switch (new Date().getDay()) {
  case 0:
    mensagem += "domingo";
    break;

  case 1:
    mensagem += "segunda-feira";
    break;

  case 2:
    mensagem += "terça-feira";
    break;

  case 3:
    mensagem += "quarta-feira";
    break;

  case 4:
    mensagem += "quinta-feira";
    break;

  case 5:
    mensagem += "sexta-feira";
    break;

  case 6:
    mensagem += "sábado";
    break;
}

document.querySelector("#msg").innerHTML = mensagem;
