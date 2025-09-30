const cachorro = {
  raca: "Border Collie",
  nome: "Bidu",
  sobrenome: "Borderer",
  idade: 10,
  peso: 16.5,
};

console.log(cachorro.nome);
console.log(cachorro["idade"]);

let p = "peso";

console.log(cachorro[p]);

cachorro.dono = "Gustavo";

console.log(cachorro);
