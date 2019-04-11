type state = {currentCity: option(Data.city)};

type action =
  | UpdateCity(Data.city);

[@react.component]
let make = () => {
  let (state, dispattcher) =
    React.useReducer(
      (_state, action) =>
        switch (action) {
        | UpdateCity(city) => {currentCity: Some(city)}
        },
      {currentCity: None},
    );

  <div>
    <h1> {React.string("Cities")} </h1>
    {List.map(
       (city: Data.city) =>
         <City
           onClick={city => dispattcher(UpdateCity(city))}
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
};
