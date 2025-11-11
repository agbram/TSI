const input = document.createElement("input");
input.placeholder = "Digite uma tarefa";

const botao = document.createElement("button");
botao.textContent = "Adicionar";

const lista = document.createElement("ul");

document.body.appendChild(input);
document.body.appendChild(botao);
document.body.appendChild(lista);

let tarefas = JSON.parse(localStorage.getItem("tarefas")) || [];

function salvarTarefas() {
  localStorage.setItem("tarefas", JSON.stringify(tarefas));
}

function renderizarTarefas() {
  lista.innerHTML = ""; //
  tarefas.forEach((tarefa, index) => {
    const li = document.createElement("li");
    li.textContent = tarefa;

    const removerBtn = document.createElement("button");
    removerBtn.textContent = "Remover";
    removerBtn.style.marginLeft = "10px";

    removerBtn.addEventListener("click", () => {
      tarefas.splice(index, 1); 
      salvarTarefas();          
      renderizarTarefas();      
    });

    li.appendChild(removerBtn);
    lista.appendChild(li);
  });
}

// Adicio
botao.addEventListener("click", () => {
  const texto = input.value.trim();
  if (texto !== "") {
    tarefas.push(texto);
    salvarTarefas();
    renderizarTarefas();
    input.value = "";
  }
});

renderizarTarefas();