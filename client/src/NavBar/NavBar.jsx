import { useState, useEffect, useContext } from "react";
import { NavLink } from "react-router-dom";
import { Context } from "../Provider";
import { Link } from "react-router-dom";
import Logout from "../Login-Form/Logout";
import MyAwesomeThemeComponent from "../ThemeToggle/toggle";
const NavBar = () => {
  const { provider } = useContext(Context);
  const [prevScrollPos, setPrevScrollPos] = useState(0);
  const [visible, setVisible] = useState(true);
  const [top, setTop] = useState(true);
  const handleScroll = () => {
    const currentScrollPos = window.pageYOffset;
    if (currentScrollPos === 0) {
      setTop(true);
    } else {
      setTop(false);
    }
    setVisible(prevScrollPos > currentScrollPos || currentScrollPos < 10);
    setPrevScrollPos(currentScrollPos);
  };
  useEffect(() => {
    window.addEventListener("scroll", handleScroll);
    return () => window.removeEventListener("scroll", handleScroll);
  }, [prevScrollPos, visible, handleScroll]);

  return (
    <div
      className={`fixed w-full z-50 ${
        top
          ? "bg-base-300"
          : "backdrop-blur-md bg-neutral bg-opacity-10 transition duration-300 ease-in-out"
      }  shadow-md   ${visible ? "top-0" : "-top-full"}`}
    >
      <div className="navbar justify-between px-3 container mx-auto lg:max-w-screen-xl">
        <div className="flex gap-1 items-center">
          <svg
            className="fill-[#38bdf8]"
            height="48px"
            width="48px"
            viewBox="0 0 1024 1024"
            xmlns="http://www.w3.org/2000/svg"
          >
            <g id="SVGRepo_bgCarrier" strokeWidth="0"></g>
            <g id="SVGRepo_tracerCarrier" strokeLinecap="round" strokeLinejoin="round"></g>
            <g id="SVGRepo_iconCarrier">
              <path d="M197.769 791.767l60.672-286.853c2.341-11.066-4.733-21.934-15.799-24.275s-21.934 4.733-24.275 15.799l-60.672 286.853c-2.341 11.066 4.733 21.934 15.799 24.275s21.934-4.733 24.275-15.799zm571.063-286.786l61.778 287.068c2.38 11.058 13.273 18.093 24.33 15.713s18.093-13.273 15.713-24.33l-61.778-287.068c-2.38-11.058-13.273-18.093-24.33-15.713s-18.093 13.273-15.713 24.33z"></path>
              <path d="M967.45 386.902L535.9 208.126c-10.609-4.399-30.569-4.442-41.207-.088L57.821 386.901l436.881 178.857c10.624 4.355 30.583 4.313 41.207-.085L967.45 386.901zM551.583 603.516c-20.609 8.533-51.787 8.599-72.409.145L24.437 417.494c-32.587-13.359-32.587-47.847.009-61.188l454.73-186.174c20.641-8.448 51.818-8.382 72.407.156l448.836 185.936c32.466 13.442 32.466 47.913.004 61.354l-448.84 185.938zm288.673 166.569c-98 57.565-209.669 88.356-325.888 88.356-116.363 0-228.162-30.866-326.246-88.564-9.749-5.735-22.301-2.481-28.036 7.268s-2.481 22.301 7.268 28.036c104.336 61.377 223.297 94.22 347.014 94.22 123.564 0 242.386-32.763 346.634-93.998 9.753-5.729 13.015-18.279 7.286-28.032s-18.279-13.015-28.032-7.286z"></path>
              <path d="M983.919 383.052v296.233c0 11.311 9.169 20.48 20.48 20.48s20.48-9.169 20.48-20.48V383.052c0-11.311-9.169-20.48-20.48-20.48s-20.48 9.169-20.48 20.48z"></path>
            </g>
          </svg>
          <div className="text-2xl text-[#38bdf8] underline font-bold navbar-start">SmartED</div>
        </div>

        <div className="navbar-center">
          <MyAwesomeThemeComponent />
        </div>

        <div className="navbar-end">
          <ul className="menu menu-horizontal gap-1 rounded-box">
            <div className="dropdown ml-3">
              <label tabIndex={0} className="btn btn-ghost btn-circle avatar avatar-online">
                <div className="w-12 bg-primary rounded-full avatar-online">
                  <img src={`http://localhost:9999/photos/${provider.currentUser.img}`} />
                </div>
              </label>
              <ul
                tabIndex={0}
                className="menu dropdown-content mt-3 p-2 shadow-lg bg-primary-content text-base-content rounded-box w-52"
              >
                <li>
                  <Link to={`/profile/${provider.currentUser._id}`}>Profile</Link>
                </li>
                <li>
                  <Link to="/logout">Logout</Link>
                </li>
              </ul>
            </div>
          </ul>
        </div>
      </div>
    </div>
  );
};
export default NavBar;
