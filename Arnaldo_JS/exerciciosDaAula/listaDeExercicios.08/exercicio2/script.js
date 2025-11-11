function getCookie(nome) {
  const cookies = document.cookie.split("; ");
  for (let c of cookies) {
    const [chave, valor] = c.split("=");
    if (chave === nome) return valor;
  }
  return null;
}

// Verifica se já existe o cookie "username"
let username = getCookie("username");

if (!username) {
  // Se não existe, pede o nome
  username = prompt("Qual é o seu nome?");

  if (username) {
    // Cria data de expiração para 30 dias no futuro
    const data = new Date();
    data.setDate(data.getDate() + 30);

    // Salva o cookie
    document.cookie = `username=${username}; expires=${data.toUTCString()}; path=/`;
  }
}

// Exibe a saudação na página
if (username) {
  const mensagem = document.createElement("h2");
  mensagem.textContent = `Olá, ${username}!`;
  document.body.appendChild(mensagem);
}