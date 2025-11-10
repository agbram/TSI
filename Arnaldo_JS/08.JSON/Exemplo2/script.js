function exibeEndereco(endereco){
    const form = document.querySelector("form");

    form.log.value = endereco.street;
    form.bairro.value = endereco.neighborhood;
    form.cidade.value = endereco.city;
    form.estado.value = endereco.state;

    let p = document.createElement("p")
    p.innerHTML = "Dados fornecidos por " + endereco.service;
    
    form.appendChild(p);
    
}
async function obterEndereco(){

    //contrução da url
    let url = "https://brasilapi.com.br/api/cep/v1/"
    url += this.value


    //requisição à API
    let response = await fetch(url);

    if(response.ok){

        //converte a resposta para JSON
        let json = await response.json();

        console.log(json);

        exibeEndereco(json);

    } else {
        console.log("Problema em buscar o CEP");
    }

}

const cep = document.querySelector("#cep");
cep.onchange = obterEndereco;
