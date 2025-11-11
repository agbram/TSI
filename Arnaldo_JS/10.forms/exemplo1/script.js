const form = document.querySelector("#myform");
const nameInput = document.querySelector("#name");
const nameError = document.querySelector("#name-error");
const passwordInput = document.querySelector("#password");
const passwordError = document.querySelector("#password-error");
const cpassword = document.querySelector("#cpassword");
const cpasswdError = document.querySelector("#cpassword-error");

passwordInput.addEventListener("input", () => {
  passwordInput.textContent = "";

  if (passwordInput.validity.patternMismatch) {
    const errorMsg =
      "A senha deve ter no mínimo 6 caracteres, com pelo menos uma letra maiúscula e um número.";
    passwordError.textContent = errorMsg;
    passwordInput.setCustomValidity(errorMsg);
  } else {
    passwordInput.setCustomValidity("");
  }

  if (cpassword.value !== "") {
    validateConfirmPassword();
  }
});

cpassword.addEventListener("input", () => {
  validateConfirmPassword();
});

cpassword.addEventListener("input", () => {
  validateConfirmPassword();
});

nameInput.addEventListener("input", () => {
  //apaga o conteudo da tag span de erro
  nameError.textContent = "";

  //se houver erro de padrao (atributo pattern)
  if (nameInput.validity.patternMismatch) {
    //crio mensagme de erro
    const errorMsg = "Invalid name pattern";

    //coloco a mensagem dentro da tag span de erro
    nameError.textContent = errorMsg;

    //sinalizo o erro para a API Constraint Validation
    nameInput.setCustomValidity(errorMsg);
  } else {
    //a chamada do metodo com string vazia significa que não houve err
    nameInput.setCustomValidity("");
  }
});

//submissão do form
form.addEventListener("submit", (e) => {
  //previne o comportamento padrão do evento
  //submit: cancela o envio do forms
  e.preventDefault();

  //se todos os campos estiverem válidos
  if (form.checkValidity()) {
    //submeto o forms
    alert("Formulário enviado com sucesso!");
    form.submit();
  } else {
    alert("Formulário inválido! Revise os campos e tente novamente.");
    console.log("Formulário inválido");
  }
});
