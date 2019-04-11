open Data;

let array_of_record = ({lat, lng}) => [|lat, lng|];

[@react.component]
let make = (~city, ~onClick) =>
  <div onClick={_e => onClick(city)}> {React.string(city.name)} </div>;
