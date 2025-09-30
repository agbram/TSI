// const person = {
//     firstName: "Gustavo",
//     lastName: "Braga",
//     id: 1,
//     fullName: function() {
//         return this.firstName + " " + this.lastName;
//     }
// }

// function Person(first, last, id){
//     this.firstName = first;
//     this.lastName = last;
//     this.id = id;
//     this.peso = 0;
//     this.idade = 0;

//     this.fullName = function() {
//         return this.firstName + " " + this.lastName;
//     }
// };
//     const p1 = new Person("Gustavo", "Braga", 1);
//     const p2 = new Person("Bernardo", "Braga", 1);
//     const p3 = new Person("Raimundo Wellington", "de Matos", 1);

//     console.log(p1.fullName());
//     console.log(p2.fullName());
//     console.log(p3.fullName());

class Person {
  constructor(first, last, id) {
    this.firstName = first;
    this.lastName = last;
    this.id = id;
    this.peso = 0;
    this.idade = 0;
  }
  fullName() {
    return this.firstName + " " + this.lastName;
  }
}
const p1 = new Person("Gustavo", "Braga", 1);
const p2 = new Person("Bernardo", "Braga", 1);
const p3 = new Person("Raimundo Wellington", "de Matos", 1);


// console.log(p1.fullName());
// console.log(p2.fullName());
// console.log(p3.fullName());


// for (let prop in p1) {
//   console.log(`${prop}: ${p1[prop]}`);
// }


// for(let[prop, value] of Object.entries(p1)){
//     console.log(`${prop}: ${value}`);
// }


// let {firstName, lastName} = p1;

// console.log(firstName);
