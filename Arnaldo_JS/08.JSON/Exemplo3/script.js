function exibirPessoa(pessoa){
    const divUser = document.querySelector(".user");
    divUser.innerHTML = ""

    //imagem
    let img = document.createElement("img");
    img.src = pessoa.picture.large;

    let nome = `${pessoa.name.first} ${pessoa.name.last}`
    let par = document.createElement("p");
    par.innerHTML = "Nome: " + nome;
    
    let rua = `Rua: ${pessoa.location.street.name}, ${pessoa.location.street.number}`
    
    let paragrafoRua = document.createElement("p");
    paragrafoRua.innerHTML = rua;

    let cidade = `Cidade: ${pessoa.location.city}`
    let paragrafoCidade = document.createElement("p");
    paragrafoCidade.innerHTML = cidade;

    let pais = `Nacionalidade: ${pessoa.location.country}`
    let paragrafoPais = document.createElement("p");
    paragrafoPais.innerHTML = pais;
    
    
    

    
    

    divUser.appendChild(img);
    divUser.appendChild(par);
    
}

async function obterNovaPessoa(){
    let url = "https://randomuser.me/api/?nat=br";
    let resposta = await fetch(url);

    if(resposta.ok){

        let json = await resposta.json();

        console.log(json);

        //envio o primeiro elemento do array results
        exibirPessoa(json.results[0]);

    } else {

        console.log("Falhou em buscar a resposta.")

    }

}

window.onload = obterNovaPessoa;

const botao = document.querySelector("#botao");

botao.onclick = obterNovaPessoa;