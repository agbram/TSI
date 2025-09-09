function imprimeConsole(msg){
    console.log(msg);
}

function imprimeAlert(msg){
    alert(msg);
}

imprimeHTML = (msg) => {
    document.querySelector("#demo").innerHTML = msg;
}

imprimeMensagem = (nome, imprime) =>{
    let mensagem = "Olá " + nome + "!";

    imprime(mensagem);
}

imprimeMensagem("João", imprimeConsole);
imprimeMensagem("Maria", imprimeAlert);
imprimeMensagem("Antonio", imprimeHTML);