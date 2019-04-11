open Data

[@react.component]
let make = () => {
  <div>
    <h1> {React.string("Cities")} </h1>
    {List.map((city => <City key=city.id city=city />), cities)
      |> Array.of_list
      |> React.array}
  </div>
}