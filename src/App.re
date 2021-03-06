type state = {currentCity: option(Data.city)};

type action =
  | UpdateCity(Data.city);

module List = {
  include List
  let find_opt = (f, l) => {
    switch(List.find(f, l)) {
      | item => Some(item)
      | exception Not_found => None
    }
  }
}

open ReasonReactRouter;
open Data;

[@react.component]
let make = () => {
  let {path} = useUrl();
  let (state, dispatcher) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | UpdateCity(city) => {currentCity: Some(city)}
        },
      {currentCity: None},
    );
let default_content =
  <div>
    <h1> {React.string("Cities")} </h1>
    {List.map(
       (city: Data.city) =>
         <City
           onClick={city => dispatcher(UpdateCity(city))}
           key={city.id}
           city
         />,
       Data.cities,
     )
     |> Array.of_list
     |> React.array}
    {switch (state.currentCity) {
     | None => React.null
     | Some(city) => <MapContainer city />
     }}
  </div>;

  switch (path) {
    | ["cities", city] => 
      switch(List.find_opt((city_data => city_data.name === city),
      Data.cities)) {
        | Some(city_data) =>
          <div>
          <MapContainer city=city_data />
          <button
            type_="button"
            onClick={_ => ReasonReactRouter.push("/")}>
            {ReasonReact.string("Go back")}
          </button>
          </div>
        | None => default_content
      }
    | _ => default_content
    };
  

};