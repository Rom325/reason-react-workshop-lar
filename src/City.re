open Data;
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
let make = (~city, ~onClick) =>
  <div onClick={_ => onClick(city)}> <img src={city.image.url} /> </div>;
