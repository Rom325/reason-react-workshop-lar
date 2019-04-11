open Data;
<<<<<<< HEAD
=======

module Map = {
  [@react.component] [@bs.module "react-leaflet"]
  external make:
    (
      ~center: array(float)=?,
      ~style: ReactDOMRe.Style.t=?,
      ~zoom: int,
      ~children: 'a
    ) =>
    React.element =
    "Map";
};

module TileLayer = {
  [@react.component] [@bs.module "react-leaflet"]
  external make: (~url: string, ~attributionUrl: string=?) => React.element =
    "TileLayer";
};
module Marker = {
  [@react.component] [@bs.module "react-leaflet"]
  external make: (~position: array(float), ~children: 'a) => React.element =
    "Marker";
};

module Popup = {
  [@react.component] [@bs.module "react-leaflet"]
  external make: (~children: 'a) => React.element = "Popup";
};

let style = ReactDOMRe.Style.make(~width="300px", ~height="300px", ());

let array_of_record = ({lat, lng}) => [|lat, lng|];

[@react.component]
let make = (~city) => {
  let position = array_of_record(city.coordinates);
  <div>
    <Map center=position zoom=13 style>
      <TileLayer
        url="https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png"
        attributionUrl=?{city.image.attributionUrl}
      />
      <Marker position> <Popup> <img src={city.image.url} /> </Popup> </Marker>
    </Map>
  </div>;
};
